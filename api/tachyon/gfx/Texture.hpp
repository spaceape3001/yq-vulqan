////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Asset.hpp>
#include <math/shape/Size3.hpp>

namespace yq::tachyon {
    class Texture : public Asset {
        YQ_OBJECT_DECLARE(Texture, Asset)
    public:
    
        static TypedAssetFactory<Texture>&  cache();
        static const Texture*       load(std::string_view);
    
        //  TODO
    
        Texture();
    private:
        ~Texture();
    };
}
