#ifndef RUBY_NATIVE_UI_MULTI_SELECTION_BOX_H
#define RUBY_NATIVE_UI_MULTI_SELECTION_BOX_H

#include <yui/YMultiSelectionBox.h>
#include "ui.h"

void init_ui_multi_selection_box();

extern VALUE cUIMultiSelectionBox;
VALUE ui_wrap_multi_selection_box(YMultiSelectionBox *box);

#endif
