# AudioExtractor

AudioExtractor — это простое консольное приложение на Qt, которое позволяет извлекать аудио из видеофайлов и сохранять его в формате MP3. Приложение поддерживает перетаскивание файлов (Drag and Drop) и не требует графического интерфейса.

## Установка

1. Убедитесь, что у вас установлен [FFmpeg](https://ffmpeg.org/download.html) и он доступен в переменной окружения PATH.
3. Загрузите исполняемый файл `getAudio.exe` из последнего релиза.

## Использование

### Запуск

1. Перетащите видеофайл на исполняемый файл `getAudio.exe`.
2. Аудиофайл будет извлечен и сохранен в директории, где находится видеофайл.

### Дополнительно

Поддерживаемые форматы:
Видео: MP4, AVI, MKV и другие форматы, поддерживаемые FFmpeg.
Аудио: MP3.

Если аудиофайл с именем видеофайла уже существует, приложение создаст новый файл с добавленным номером в скобках перед расширением (например, audio (1).mp3).
Приложение выводит сообщения об ошибках в консоль, если возникают проблемы с извлечением аудио.
