#! UI Framework

Aiming for a light weight structured approach to ImGui, the UI framework should allow for simpler syntax.  This UI can be defined in the widget info.

```
void MyClassWidget::init_info()
{
    auto w = writer<MyClassWidget>();
    auto app = w.imgui(UI, APP);
    auto mmb = app.menubar(MAIN);
    auto file = mmb.menu("File");
    auto edit = mmb.menu("Edit");
    auto undo = edit.menuitem("Undo");
    auto tb = mmb.toolbar("Tools");
    
    // and more definition
    
    // alternatively, once this is implemented, could go
    w.imgui(UI, "MyClassWidget.ui");
}

void MyClassWidget::imgui(ViContext& u)
{
    Widget::imgui(UI,u);
}
```

## Naming

All components in this framework are prefixed with "UI" in the `yq::tachyon` namespace.


... MORE TODO ...

