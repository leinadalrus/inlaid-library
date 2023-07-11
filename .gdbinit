set pagination on
set logging file gdb.output
set logging on

set width 0
set height 0
set verbose on

break main if argc >= 3
  print "Breakpoint occurred/ \
    \n \t meant to occur for: \
      \n \t Main Thread Program[!?]"
  call check_memblc_alignas
  backtrace full
  continue
end

run

set logging off
quit
