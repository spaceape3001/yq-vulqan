////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "preamble.hpp"
#include <span>

namespace yq {
    namespace engine {
    
        /*! \brief A pixmap is an image
        
            This is a generic API for a pixel map, ie, an array of them.
        */
        class Pixmap : public RefCount {
        public:
        
            //! Format of the data
            DataFormat                      format() const { return m_format; }
            
            //! "Type" of the image (ie, 1/2/3 dimensions */
            virtual ImageType               image_type() const = 0;
            
            //! Data for the image
            virtual std::span<std::byte>    data() const = 0;
            
            //! Number of pixes
            virtual size_t                  pixel_count() const = 0;
            
            //! Byte size of the pixels
            virtual size_t                  pixel_size() const = 0;
            
            //! Image width (valid 1D/2D/3D)
            virtual size_t                  width() const { return 1ULL; }
            
            //! Image height (valid 2D/3D)
            virtual size_t                  height() const { return 1ULL; }
            
            //! Image depth (valid 3D)
            virtual size_t                  depth() const { return 1ULL; }
            
            //! Number of dimensions
            virtual uint8_t                 dims() const = 0;
            
        protected:
            Pixmap(){}
            virtual ~Pixmap(){}
            
            DataFormat                      m_format;
        };
    };
}
