////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string_view>

namespace yq::tachyon {

    //! General cardinal directions..
    enum class UICardinal {
        Unknown,    //!< Unknown cardinal direction
        Center,     //!< Center of the area
        NW,         //!< Northwest corner (exactly)
        NNW,        //!< North by Northwest
        North,      //!< North
        NNE,        //!< North by Northeast
        NE,         //!< North East
        ENE,        //!< East-by-northeast
        East,       //!< East
        ESE,        //!< East by Southeast
        SE,         //!< South East
        SSE,        //!< South by Southeast
        South,      //!< South
        SSW,        //!< South by Southwest
        SW,         //!< Southwest
        WSW,        //!< West by Southwest
        West,       //!< West
        WNW         //!< West by Northwest
    };
    
    bool    is_north(UICardinal);
    bool    is_south(UICardinal);
    bool    is_east(UICardinal);
    bool    is_west(UICardinal);
    
    std::string_view    key_for(UICardinal);
    std::string_view    pretty_for(UICardinal);
}


