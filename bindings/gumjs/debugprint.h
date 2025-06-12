
#define ENABLE_DEBUG_PRINTS 0

// XXX for debugging prints
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define ORANGE  "\033[33m"      /* Orange */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

#if ENABLE_DEBUG_PRINTS

// g_print with color on tag only
#define GPRINT_CTAG(colorTag, tag, format, ...) \
    g_print(colorTag tag RESET " " "[%lu]" " " format, gum_process_get_current_thread_id(),  ##__VA_ARGS__); \
// g_print with color
#define GPRINT_C(color, format, ...) \
  g_print(color format RESET, ##__VA_ARGS__)
// g_print with colot on tag ijf self->is_cancelled
#define GPRINT_CTAG_IC(colorTag, tag, format, ...) \
  do { \
    if (self->is_cancelled) { \
      g_print(colorTag tag RESET " " "[%lu]" " " format, gum_process_get_current_thread_id(),  ##__VA_ARGS__); \
    } \
  } while (0)
// g_print with color  if self->is_cancelled
#define GPRINT_C_IC(color, format, ...) \
  do { \
    if (self->is_cancelled) { \
      g_print(color format RESET, ##__VA_ARGS__); \
    } \
  } while (0)

#else

#define GPRINT_CTAG(colorTag, tag, format, ...)      ((void)0)
#define GPRINT_C(color, format, ...)                 ((void)0)
#define GPRINT_CTAG_IC(colorTag, tag, format, ...)   ((void)0)
#define GPRINT_C_IC(color, format, ...)              ((void)0)

#endif
