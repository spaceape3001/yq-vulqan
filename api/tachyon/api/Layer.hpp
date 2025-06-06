////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/typedef/layer.hpp>

namespace yq::tachyon {
    class LayerInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;
        LayerInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    protected:
        ~LayerInfo();
    };
    
    /*! \brief Layer/Group of things (context provided by its parent)
    */
    class Layer : public Tachyon {
        YQ_TACHYON_INFO(LayerInfo)
        YQ_TACHYON_DATA(LayerData)
        YQ_TACHYON_SNAP(LayerSnap)
        YQ_TACHYON_DECLARE(Layer, Tachyon)
    public:
    
        Layer(const Param&p={});
        virtual ~Layer();
        
        static void init_info();
        
        LayerID id() const { return LayerID{ UniqueID::id()}; }
        
        //! Loose informal "order" to the layers... (implicitly by order added to parent otherwise)
        int             order() const { return m_order; }
        virtual void    set_order(int);

    protected:
        
        void    snap(LayerSnap&) const;
        void    finalize(LayerData&) const;
        
    private:
        int     m_order = 0;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::LayerID)
