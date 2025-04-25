////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/scene/SimpleScene3.hpp>
#include <tachyon/api/Scene3InfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleScene³)

namespace yq::tachyon {
    SimpleScene³::SimpleScene³() : Scene³({})
    {
    }
    
    SimpleScene³::~SimpleScene³()
    {
    }

    void    SimpleScene³::snap(Scene³Snap& sn) const
    {
        Scene³::snap(sn);
        for(const TypedID& t : sn.children){
            if(t(Type::Camera))
                sn.cameras.push_back(t);
            if(t(Type::Light))
                sn.lights.push_back(t);
            if(t(Type::Rendered))
                sn.rendereds.push_back(t);
        }
    }
    
    void SimpleScene³::init_info()
    {   
        auto w = writer<SimpleScene³>();
        w.description("Simple 3D Scene, using child/parenting");
    }
}
