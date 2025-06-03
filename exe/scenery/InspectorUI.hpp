////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

using namespace yq;
using namespace yq::tachyon;

class InspectorUI : public UIEditor {
    YQ_OBJECT_DECLARE(InspectorUI, UIEditor)
public:

    static void init_info();

    InspectorUI(UIFlags flags={});
    InspectorUI(const InspectorUI&);
    ~InspectorUI();
    
    virtual InspectorUI* clone() const override;
    virtual bool bind(TypedID) override;
    virtual void render() override;

private:
    struct Repo;
    static Repo& repo();
};

