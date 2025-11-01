////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class TachyonMeta;

    // UIShapes
    class UIInfoList : public UIElement {
        YQ_OBJECT_DECLARE(UIInfoList, UIElement)
    public:

        static void init_meta();

        UIInfoList(std::string_view szTitle={}, UIFlags flags={});
        
        UIInfoList(const UIInfoList& cp);
        ~UIInfoList();
        virtual UIInfoList* clone() const = 0;
        virtual const char* title() const override;
        virtual void render() override;
        
        const TachyonMeta*  selected() const { return m_selected; }
        
    protected:
        //! Gets the data (note, only called on first use OR whenever it's stale)
        virtual std::vector<const TachyonMeta*> get_infos() const = 0;
        
    private:
        struct Row;
        void                define_rows();
        std::vector<Row>    m_rows;
        std::string         m_title;
        const TachyonMeta*  m_selected  = nullptr;
    };
}
