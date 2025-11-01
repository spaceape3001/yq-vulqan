////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/typedef/layer.hpp>

namespace yq::tachyon {
    class LayerMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;
        LayerMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~LayerMeta();
    };
    
    /*! \brief Layer/Group of things (context provided by its parent)
    */
    class Layer : public Tachyon {
        YQ_TACHYON_META(LayerMeta)
        YQ_TACHYON_DATA(LayerData)
        YQ_TACHYON_SNAP(LayerSnap)
        YQ_TACHYON_DECLARE(Layer, Tachyon)
    public:
    
        Layer(const Param&p={});
        virtual ~Layer();
        
        static void init_meta();
        
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
