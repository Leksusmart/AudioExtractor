#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <iostream>
#include <windows.h>

QString generateUniqueFileName(const QString &basePath)
{
   QString uniquePath = basePath;
   int counter = 1;

   QFileInfo fileInfo(uniquePath);
   QString baseName = fileInfo.baseName(); // Получаем имя файла без расширения
   QString extension = fileInfo.suffix();  // Получаем расширение файла

   // Проверяем, существует ли файл
   while (QFile::exists(uniquePath)) {
      uniquePath = QString("%1 (%2).%3").arg(baseName, QString::number(counter), extension); // Добавляем номер к имени перед расширением
      counter++;
   }

   return uniquePath;
}

int main(int argc, char *argv[])
{
   SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодовую страницу вывода на UTF-8
   QCoreApplication a(argc, argv);

   if (argc < 2) {
      std::cout << "RU" << std::endl;
      std::cout << "Как использовать: Перетащите видео файл на getAudio.exe и получите аудио в .mp3 туда где находится видео файл" << std::endl;
      std::cout << "EN" << std::endl;
      std::cout << "How to use: Drag and drop a video file onto getAudio.exe and receive the audio in .mp3 where the video file is located." << std::endl;

      a.exec();
   } else {
      QString videoPath = argv[1];
      QFileInfo fileInfo(videoPath);
      QString audioPath = QDir::currentPath() + "/" + fileInfo.baseName() + ".mp3"; // Сохраняем в текущую директорию

      // Генерируем уникальное имя файла, если файл уже существует
      audioPath = generateUniqueFileName(audioPath);

      // Формируем команду для извлечения аудио с помощью FFmpeg
      QStringList arguments;
      arguments << "-i" << videoPath << "-map" << "0:a:0" << "-q:a" << "0" << audioPath; // Извлекаем только первый аудиопоток

      QProcess process;
      process.start("ffmpeg", arguments);

      // Ждем завершения процесса
      if (!process.waitForFinished()) {
         qDebug() << "Error:" << process.errorString();
         a.exec();
      } else {
         return 0;
      }
   }
}
