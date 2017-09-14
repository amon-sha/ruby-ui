#include "widget.h"
#include "exception_guard.h"
#include "selection_widget.h"
#include "multi_selection_box.h"

static void
dealloc(YMultiSelectionBox *box)
{
  widget_object_map_remove(box);
}

VALUE
ui_wrap_multi_selection_box(YMultiSelectionBox *box)
{
  return Data_Wrap_Struct(cUIMultiSelectionBox, ui_selection_widget_mark, dealloc, box);
}

YMultiSelectionBox *
ui_unwrap_multi_selection_box(VALUE box)
{
  YMultiSelectionBox *ptr = 0L;
  Data_Get_Struct(box, YMultiSelectionBox, ptr);
  return ptr;
}

VALUE cUIMultiSelectionBox;
void init_ui_multi_selection_box()
{
  VALUE ui = rb_define_module("UI");

  VALUE klass = rb_define_class_under(ui, "MultiSelectionBox", cUISelectionWidget);
  cUIMultiSelectionBox = klass;
}

