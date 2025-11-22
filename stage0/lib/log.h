#ifndef LOG_H
#define LOG_H

#define LOG_INFO    1
#define LOG_WARNING 2
#define LOG_ERROR   3

void pearl_log(int level, const char *message);
#endif // LOG_H