////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string_view>

namespace yq::tachyon {

    //! General cardinal directions..
    enum class Cardinal {
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
    
    bool    is_north(Cardinal);
    bool    is_south(Cardinal);
    bool    is_east(Cardinal);
    bool    is_west(Cardinal);
    
    std::string_view    key_for(Cardinal);
    std::string_view    pretty_for(Cardinal);
}


