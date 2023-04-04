////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>
#include <variant>
#include <filesystem>

namespace yq {
    namespace tachyon {
        class EditorInfo : public WidgetInfo {
        public:
            
            template <typename C>  struct Writer;
            
            EditorInfo(std::string_view, tachyon::WidgetInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        using EditorSpec    = std::variant<std::monostate, uint64_t, std::filesystem::path, std::string>;
        
        class Editor : public Widget {
            YQ_OBJECT_INFO(EditorInfo)
            YQ_OBJECT_DECLARE(Editor, Widget)
        public:
        
            virtual bool    load(EditorSpec) = 0;
            
            //virtual void    draw_menubar(){}
            //virtual void    draw_content(){}
            
            virtual void    draw(/*engine::UiData&*/) override;
            
            const std::filesystem::path&    file() const { return m_file; }
            
            virtual ~Editor();
            
        protected:

            std::filesystem::path   m_file;
        
            Editor();
        };
    }
}
