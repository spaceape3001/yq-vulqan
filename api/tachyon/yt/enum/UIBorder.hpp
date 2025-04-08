////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    enum class UIBorder : uint8_t {
        //! NW corner, expand along north side (ie, horizontal)
        NNW, 
        
        //! North side, centered
        North, 
        
        //! NE corner, expand along north side (ie horizontal)
        NNE, 
        
        //! NE corner, expand along east side (ie vertical)
        ENE, 
        
        //! East side, centered
        East, 
        
        //! SE corner, expand along east side (ie vertical)
        ESE, 
        
        //! SE corner, expand along south side (ie horizontal)
        SSE, 
        
        //! South side, centered
        South, 
        
        //! SW corner, expand along south side (ie horizontal)
        SSW, 
        
        //! SW corner, expand along west side (ie vertical) 
        WSW, 
        
        //! West side, centered
        West, 
        
        //! NW corner, expand along west side (ie vertical)
        WNW
    };
}
