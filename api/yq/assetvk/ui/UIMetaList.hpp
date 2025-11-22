////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class TachyonMeta;

    // UIShapes
    class UIMetaList : public UIElement {
        YQ_OBJECT_DECLARE(UIMetaList, UIElement)
    public:

        static void init_meta();

        UIMetaList(std::string_view szTitle={}, UIFlags flags={});
        
        UIMetaList(const UIMetaList& cp);
        ~UIMetaList();
        virtual UIMetaList* clone() const = 0;
        virtual const char* title() const override;
        virtual void render() override;
        
        const Meta*  selected() const { return m_selected; }
        
    protected:
        //! Gets the data (note, only called on first use OR whenever it's stale)
        virtual std::vector<const Meta*> get_metas() const = 0;
        
    private:
        struct Row;
        void                define_rows();
        std::vector<Row>    m_rows;
        std::string         m_title;
        const Meta*         m_selected  = nullptr;
    };
}
