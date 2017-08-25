#include "ui_log.h"

VALUE mUILog;

static VALUE get_debug_logging_enabled(VALUE self)
{
  return YUILog::debugLoggingEnabled() ? Qtrue : Qfalse;
}

static VALUE set_debug_logging_enabled(VALUE self, VALUE value)
{
  YUILog::enableDebugLogging(RTEST(value));
  return value;
}

static VALUE log_file_name(VALUE self)
{
  return rb_str_new2(YUILog::logFileName().c_str());
}

static VALUE set_log_file_name(VALUE self, VALUE value)
{
  YUILog::setLogFileName(StringValueCStr(value));
  return value;
}

void init_ui_ui_log()
{
  VALUE mUI = rb_define_module("UI");
  mUILog = rb_define_module_under(mUI, "Log");

  rb_define_singleton_method(mUILog, "debug_logging_enabled?", RUBY_METHOD_FUNC(get_debug_logging_enabled), 0);
  rb_define_singleton_method(mUILog, "debug_logging_enabled=", RUBY_METHOD_FUNC(set_debug_logging_enabled), 1);
  rb_define_singleton_method(mUILog, "filename", RUBY_METHOD_FUNC(log_file_name), 0);
  rb_define_singleton_method(mUILog, "filename=", RUBY_METHOD_FUNC(set_log_file_name), 1);
}

