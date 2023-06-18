////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    /*! \brief Type of push configuration
    
        This is the general type of push configuration a pipeline uses;
        two are explicitly called out for better runtime performance
    */
    enum PushConfigType : uint8_t {
        //! No push data
        None        = 0,
        //! Full model->screen matrix requested
        Full,
        //! Partial world->screen matrix requested
        View,
        //! Custom push data
        Custom
    };
}
