$: << File.expand_path(File.join(File.dirname(__FILE__), '../lib'))
require 'ui'

class ProgressDialog
  extend UI::Builder
  
  def self.run(&block)
    @aborted = @finished = false

    dialog = main_dialog { vcenter { vbox {
      @bar = progress_bar ''
      @button = push_button 'Abort'
    }}}

    thread = Thread.new do
      block.call(self)
    end

    dialog.wait_for_event(10) do |event|
      break if @finished
      next true if event.is_a?(UI::TimeoutEvent)
      @button[:Enabled] = false
      @aborted = true
    end
    
    thread.join
  end

  def self.update(value)
    @bar.value = value
    return :abort if @aborted
  end

  def self.finish
    @finished = true
  end
end


ProgressDialog.run do |progress|
  0.upto(100) do |i|
    sleep 0.1
    break if progress.update(i) == :abort
  end
  progress.finish
end
