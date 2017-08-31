#ifndef RUBY_NATIVE_UI_COMBO_BOX_H
#define RUBY_NATIVE_UI_COMBO_BOX_H

#include <yui/YComboBox.h>
#include "ui.h"

void init_ui_combo_box();

extern VALUE cUIComboBox;
VALUE ui_wrap_combo_box(YComboBox *btn);

#endif
