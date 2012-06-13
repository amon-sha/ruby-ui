module UI
  class Widget
    alias_method :find, :find_widget

    # Defines callback when widget is activated ( e.g. clicked on button )
    # @yield [UI::Event,UI::Dialog] block that gets event when it occur and
    #     dialog where it happen
    # @yieldreturn [nil,Symbol] return value specify what do in event handling
    #     nil represents stopping of event, :cancel generate CancelEvent instead
    #     and :continue pass event further
    def activated(&block)
      @activated = block
    end

    # Fires event handler
    def activated_fire (event, dialog)
      return :continue unless @activated
      @activated.call(event, dialog)
    end

    # Defines callback when value of widget is changed
    # @see #activated
    # @yield [UI::Event] block that gets event when it occur
    # @yieldreturn [nil,Symbol] return value specify what do in event handling
    #     nil represents stopping of event, :cancel generate CancelEvent instead
    #     and :continue pass event further
    def value_change(&block)
      @value_change = block
    end

    # Fires event handler
    def value_change_fire (event, dialog)
      return :continue unless @value_change
      @value_change.call(event, dialog)
    end
  end
end
