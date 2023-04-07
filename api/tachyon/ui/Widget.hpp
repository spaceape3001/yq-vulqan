////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Object.hpp>
#include <basic/UniqueID.hpp>
#include <basic/Flags.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq {
    namespace tachyon {
        enum class WidgetBit {
            Vulkan  = 0,
            ImGui,
            D2,
            D3, // Its a graphics thing so likely?
            D4  // haven't a clue on doing 4D (spatial) "widgets"
        };
        
        using WidgetFlags   = Flags<WidgetBit>;
    
        class WidgetInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;
            WidgetInfo(std::string_view, const ObjectInfo&, const std::source_location& sl = std::source_location::current());
        
            bool            is_vulkan() const
            {
                return m_flags.is_set(WidgetBit::Vulkan);
            }
            
            bool            is_imgui() const 
            { 
                return m_flags.is_set(WidgetBit::ImGui); 
            }
            
            bool            is_2d() const
            {
                return m_flags.is_set(WidgetBit::D2);
            }
        
            bool            is_3d() const
            {
                return m_flags.is_set(WidgetBit::D3);
            }

            bool            is_4d() const
            {
                return m_flags.is_set(WidgetBit::D4);
            }

        private:
            WidgetFlags   m_flags;
        };
        
        /*! \brief Root something that's drawwable & interactable
        
            It follows ImGui's rules, this is something that is 
            "drawable" and needs some amount of state information.
        */
        class Widget : public Object, public UniqueID {    
            YQ_OBJECT_INFO(WidgetInfo)
            YQ_OBJECT_DECLARE(Widget, Object)
        public:
        
            Widget();
            virtual ~Widget();

            virtual void    imgui_(ViContext&);
            virtual void    vulkan_(ViContext&);
            
            /*! \brief Sets the parent of this widget
            
                This will fail if a parent-loop is detected.  
                (ie, trying to set to self)
            
                \param[in] p    Proposed parent (can be null)
                \return TRUE if the change was taken
            */
            bool    set_parent(Widget* p);
            
            /*! \brief Adds the child to this widget
            
                This will fail for reasons of set_parent, OR the
                child is null.
                
                \param[in] ch   Child to add
                \return TRUE if the change was taken
            */
            bool    add_child(Widget* ch);
            
            /*! \brief Tests for parentage
            
                Checks to see if the argument is this widget's parent
                or grandparent or great grandparent to whatever degree.
            
                \param p    Supposed parent in question
            */
            bool    has_parentage(const Widget* p) const;

        protected:
            Widget*                 m_parent = nullptr;
            std::vector<Widget*>    m_children;
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
                    m_meta->m_flags |= WidgetBit::ImGui;
            }
            
            void    vulkan()
            {
                if(m_meta)
                    m_meta->m_flags |= WidgetBit::Vulkan;
            }
            
            void    _2d()
            {
                if(m_meta)
                    m_meta->m_flags |= WidgetBit::D2;
            }
            
            void    _3d()
            {
                if(m_meta)
                    m_meta->m_flags |= WidgetBit::D3;
            }

            void    _4d()
            {
                if(m_meta)
                    m_meta->m_flags |= WidgetBit::D4;
            }

        private:
            WidgetInfo* m_meta;
        };
    }
}
