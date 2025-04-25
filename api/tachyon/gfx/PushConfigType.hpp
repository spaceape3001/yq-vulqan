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
        //! Separate Model-view-projection matrix... otherwise the same
        MVP,
        //! Partial view & projection (combined matrix) requested
        View,
        //! View & projection matrix requested (kept separate)
        ViewProj,
        //! View & projection matrix requested (kept separate -- view as 64-bit doubles)
        //! \note DUE TO SIZE, the MODEL MATRIX CANNOT BE LOADED INTO THIS PUSH CONSTANT
        View64Proj,
        //! Custom push data
        Custom
    };
}
