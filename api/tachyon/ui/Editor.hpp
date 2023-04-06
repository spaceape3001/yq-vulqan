////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget2.hpp>
#include <variant>
#include <filesystem>

namespace yq {
    namespace tachyon {
        class EditorInfo : public Widget2Info {
        public:
            
            template <typename C>  struct Writer;
            
            EditorInfo(std::string_view, Widget2Info&, const std::source_location& sl = std::source_location::current());
        
            bool        menu_bar() const { return m_menuBar; }
        
        private:
            bool        m_menuBar   = false;
        };
        
        using EditorSpec    = std::variant<std::monostate, uint64_t, std::filesystem::path, std::string>;
        
        class Editor : public Widget2 {
            YQ_OBJECT_INFO(EditorInfo)
            YQ_OBJECT_DECLARE(Editor, Widget2)
        public:
        
            virtual bool    load(EditorSpec) = 0;
            
            virtual void    menubar_(ViContext&){}
            virtual void    content_(ViContext&){}
            virtual void    imgui_(ViContext&) override;
            
            //virtual void    draw(/*engine::ViContext&*/) override;
            
            const std::filesystem::path&    file() const { return m_file; }
            
            virtual ~Editor();
            
        protected:

            std::filesystem::path   m_file;
        
            Editor();
        };

        template <typename C>
        class EditorInfo::Writer : public Widget2Info::Writer<C> {
        public:
        
            Writer(EditorInfo* editorInfo) : Widget2Info::Writer<C>(editorInfo)
            {
            }
            
            Writer(EditorInfo& editorInfo) : Writer(&editorInfo)
            {
            }
        };
    }
}
