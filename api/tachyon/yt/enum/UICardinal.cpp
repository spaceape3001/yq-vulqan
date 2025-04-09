////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICardinal.hpp"

namespace yq::tachyon {
    bool    is_north(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
        case UICardinal::Center:
            return false;
        case UICardinal::NW:
        case UICardinal::NNW:
        case UICardinal::North:
        case UICardinal::NNE:
        case UICardinal::NE:
        case UICardinal::ENE:
            return true;
        case UICardinal::East:
        case UICardinal::ESE:
        case UICardinal::SE:
        case UICardinal::SSE:
        case UICardinal::South:
        case UICardinal::SSW:
        case UICardinal::WSW:
        case UICardinal::West:
            return false;
        case UICardinal::WNW:
            return true;
        default:
            return false;
        }
    }
    
    bool    is_south(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
        case UICardinal::Center:
        case UICardinal::NW:
        case UICardinal::NNW:
        case UICardinal::North:
        case UICardinal::NNE:
        case UICardinal::NE:
        case UICardinal::ENE:
        case UICardinal::East:
            return false;
        case UICardinal::ESE:
        case UICardinal::SE:
        case UICardinal::SSE:
        case UICardinal::South:
        case UICardinal::SSW:
        case UICardinal::WSW:
            return true;
        case UICardinal::West:
        case UICardinal::WNW:
        default:
            return false;
        }
    }
    
    bool    is_east(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
        case UICardinal::Center:
        case UICardinal::NW:
        case UICardinal::NNW:
        case UICardinal::North:
            return false;
        case UICardinal::NNE:
        case UICardinal::NE:
        case UICardinal::ENE:
        case UICardinal::East:
        case UICardinal::ESE:
        case UICardinal::SE:
        case UICardinal::SSE:
            return true;
        case UICardinal::South:
        case UICardinal::SSW:
        case UICardinal::WSW:
        case UICardinal::West:
        case UICardinal::WNW:
        default:
            return false;
        }
    }
    
    bool    is_west(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
        case UICardinal::Center:
            return false;
        case UICardinal::NW:
        case UICardinal::NNW:
            return true;
        case UICardinal::North:
        case UICardinal::NNE:
        case UICardinal::NE:
        case UICardinal::ENE:
        case UICardinal::East:
        case UICardinal::ESE:
        case UICardinal::SE:
        case UICardinal::SSE:
        case UICardinal::South:
            return false;
        case UICardinal::SSW:
        case UICardinal::WSW:
        case UICardinal::West:
        case UICardinal::WNW:
            return true;
        default:
            return false;
        }
    }
    
    std::string_view    key_for(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
            return "Unknown";
        case UICardinal::Center:
            return "Center";
        case UICardinal::NW:
            return "NW";
        case UICardinal::NNW:
            return "NNW";
        case UICardinal::North:
            return "North";
        case UICardinal::NNE:
            return "NNE";
        case UICardinal::NE:
            return "NE";
        case UICardinal::ENE:
            return "ENE";
        case UICardinal::East:
            return "East";
        case UICardinal::ESE:
            return "ESE";
        case UICardinal::SE:
            return "SE";
        case UICardinal::SSE:
            return "SSE";
        case UICardinal::South:
            return "South";
        case UICardinal::SSW:
            return "SSW";
        case UICardinal::WSW:
            return "WSW";
        case UICardinal::West:
            return "West";
        case UICardinal::WNW:
            return "WNW";
        default:
            return "???";
        }
    }

    std::string_view    pretty_for(UICardinal v)
    {
        switch(v){
        case UICardinal::Unknown:
            return "Unknown";
        case UICardinal::Center:
            return "Center";
        case UICardinal::NW:
            return "Northwest";
        case UICardinal::NNW:
            return "North by Northwest";
        case UICardinal::North:
            return "North";
        case UICardinal::NNE:
            return "North by Northeast";
        case UICardinal::NE:
            return "Northeast";
        case UICardinal::ENE:
            return "East by Northeast";
        case UICardinal::East:
            return "East";
        case UICardinal::ESE:
            return "East by Southeast";
        case UICardinal::SE:
            return "Southeast";
        case UICardinal::SSE:
            return "South by Southeast";
        case UICardinal::South:
            return "South";
        case UICardinal::SSW:
            return "South by Southwest";
        case UICardinal::WSW:
            return "West by Southwest";
        case UICardinal::West:
            return "West";
        case UICardinal::WNW:
            return "West by Northwest";
        default:
            return "???";
        }
    }
}
