////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

using namespace yq;
using namespace yq::tachyon;

class InspectorUI : public UIEditor {
    YQ_OBJECT_DECLARE(InspectorUI, UIEditor)
public:

    static void init_meta();

    InspectorUI(UIFlags flags={});
    InspectorUI(const InspectorUI&);
    ~InspectorUI();
    
    virtual InspectorUI* clone() const override;
    virtual bool bind(TypedID) override;
    virtual void render() override;

private:
    struct Info;
    struct Repo;
    static Repo& repo();
    
    //  Eventually cache (but not now)
    
    void    _clear();
    
    void    _render(TypedID);
    
    std::map<TachyonID, std::vector<UIEditor*>>  m_panels;
    
    std::span<UIEditor*>    _panels(TypedID);
    
};

