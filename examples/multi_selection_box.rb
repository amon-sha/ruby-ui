$: << File.expand_path(File.join(File.dirname(__FILE__), '../lib'))
require 'ui'
require 'pp'
#require 'debugger'

include UI::Builder
dialog = main_dialog {
  vbox(:id => :vbox1) {
    multi_selection_box "Elements", :id => :box
    hbox {
      push_button "Show", :id => :show
      push_button "Close", :id => :cancel
    }
  }
}

class DumbClass
  def to_s
    "LOL!"
  end
end

box = dialog.find(:box)

item = UI::Item.new("Hello")

box << "Bye"
box << item
box << DumbClass.new

dialog.wait_for_event do |ev|
  if ev.is_a?(UI::WidgetEvent) && ev.widget.id == :show
    UI::Dialog.show_text(box.selected_items.map(&:label).join("\n"))
    true
  else
    break
  end
end
