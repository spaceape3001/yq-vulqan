////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Object.hpp>
#include <basic/UniqueID.hpp>
#include <meta/ObjectInfoWriter.hpp>
#include <tachyon/enum/Renderer.hpp>

namespace yq {
    namespace tachyon {
        class WidgetInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;
            WidgetInfo(std::string_view, const ObjectInfo&, const std::source_location& sl = std::source_location::current());
        
            bool            is_vulkan() const
            {
                return m_renderer.is_set(Renderer::Vulkan);
            }
            
            bool            is_imgui() const 
            { 
                return m_renderer.is_set(Renderer::ImGui); 
            }
        
        private:
            RendererFlags   m_renderer;
        };
        
        /*! \brief Root something that's drawwable
        
            It follows ImGui's rules, this is something that is "drawable" and needs some amount of state information.
        */
        class Widget : public Object, public UniqueID {    
            YQ_OBJECT_INFO(WidgetInfo)
            YQ_OBJECT_DECLARE(Widget, Object)
        public:
            
            virtual ~Widget();
            
        protected:
            Widget();
            
            //Widget*                 m_parent = nullptr;
            //std::vector<Widget*>    m_children;
            std::string             m_windowID;
        };

        template <typename C>
        class WidgetInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer(WidgetInfo* widgetInfo) : ObjectInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
            {
            }
            
            Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
            {
            }

            void    imgui()
            {
                if(m_meta)
                    m_meta->m_renderer |= Renderer::ImGui;
            }
            
            void    vulkan()
            {
                if(m_meta)
                    m_meta->m_renderer |= Renderer::Vulkan;
            }
            
        private:
            WidgetInfo* m_meta;
        };
    }
}
