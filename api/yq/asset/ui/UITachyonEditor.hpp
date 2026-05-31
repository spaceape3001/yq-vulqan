////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class UITachyonEditor : public UIEditor {
        YQ_OBJECT_DECLARE(UITachyonEditor, UIEditor)
    public:

        static void init_meta();

        UITachyonEditor(UIFlags flags={});
        UITachyonEditor(const UITachyonEditor&);
        ~UITachyonEditor();
        
        virtual UITachyonEditor* clone() const override;
        virtual bool bind(TypedID) override;
        virtual void render() override;

    private:
        struct Info;
        struct Repo;
        static Repo& repo();
        
        //  Eventually cache (but not now)
        
        std::map<TachyonID, std::vector<UIEditor*>>  m_panels;

        void                    _clear();
        std::span<UIEditor*>    _panels(TypedID);
        void                    _render(TypedID);
    };
}
