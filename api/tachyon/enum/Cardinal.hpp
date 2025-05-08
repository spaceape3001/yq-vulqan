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
    
    //! True for all pointing north of east-west line (ie, ENE...)
    bool                is_north(Cardinal);
    
    //! True for all pointing south of east-west line (ie, WSW...)
    bool                is_south(Cardinal);
    
    //! True for all pointing east of north-south line (ie SSE)
    bool                is_east(Cardinal);
    
    //! True for all pointing west of north-south line (ie NNW)
    bool                is_west(Cardinal);
    
    //! Key for the given cardinal
    std::string_view    key_for(Cardinal);
    
    //! Pretty form of the given cardinal
    std::string_view    pretty_for(Cardinal);
    
    //! True for all but unknown & center
    bool                is_edge(Cardinal);
    
    //! Tests if the cardinal can be considered horizontal
    //! \note Corners are treated as horizontal (Center & Unknown are not)
    bool                is_horizontal(Cardinal);

    //! Tests if the cardinal can be considered vertical
    //! \note Corners are treated as vertical (Center & Unknown are not)
    bool                is_vertical(Cardinal);
}


