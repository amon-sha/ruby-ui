#include "widget.h"
#include "exception_guard.h"
#include "selection_widget.h"
#include "combo_box.h"

static void
dealloc(YComboBox *box)
{
  widget_object_map_remove(box);
}

VALUE
ui_wrap_combo_box(YComboBox *box)
{
  return Data_Wrap_Struct(cUIComboBox, ui_selection_widget_mark, dealloc, box);
}

YComboBox *
ui_unwrap_combo_box(VALUE box)
{
  YComboBox *ptr = 0L;
  Data_Get_Struct(box, YComboBox, ptr);
  return ptr;
}

VALUE cUIComboBox;
void init_ui_combo_box()
{
  VALUE ui = rb_define_module("UI");

  VALUE klass = rb_define_class_under(ui, "ComboBox", cUISelectionWidget);
  cUIComboBox = klass;
}

