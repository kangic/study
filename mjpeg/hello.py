#!/usr/bin/python

from wxPython.wx import *

class MyFrame(wxApp):
    def OnInit(self):
        frame = wxFrame(NULL, -1, "Hello World")
        frame.Show(true)
        self.SetTopWindow(frame)
        return true

app = MyFrame(0)
app.MainLoop()

