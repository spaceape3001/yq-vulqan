////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Asset.hpp>
#include <math/shape/Size3.hpp>

namespace yq {
    namespace engine {
        class Texture : public Asset {
            YQ_OBJECT_DECLARE(Texture, Asset)
        public:
        
            static TypedAssetFactory<Texture>&  cache();
        
            //  TODO
        
            Texture();
        private:
            ~Texture();
        };
    }
}
