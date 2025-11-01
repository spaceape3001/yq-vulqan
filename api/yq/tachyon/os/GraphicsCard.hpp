////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/graphics_card.hpp>

namespace yq::tachyon {

    class GraphicsCard;
    
    /*! \brief GraphicsCard Information
    
        Information for keyboards.
    */
    class GraphicsCardMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all keyboard informations
        static const std::vector<const GraphicsCardMeta*>&    all();
        
        //! Standard constructor for the camera information
        GraphicsCardMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the keyboard is assumed to be simple....
    */

    /*! \brief A keyboard
    */
    class GraphicsCard : public Tachyon {
        YQ_TACHYON_META(GraphicsCardMeta);
        YQ_TACHYON_DATA(GraphicsCardData)
        YQ_TACHYON_SNAP(GraphicsCardSnap)
        YQ_TACHYON_DECLARE(GraphicsCard, Tachyon)
    public:    
    
        static void init_meta();

        GraphicsCardID            id() const { return GraphicsCardID(UniqueID::id()); }

    protected:
    
        void        snap(GraphicsCardSnap&) const;

        //! Default constructor
        GraphicsCard(const Param&p = {});
        
        //! Default destructor
        ~GraphicsCard();
        
    };

}

YQ_TYPE_DECLARE(yq::tachyon::GraphicsCardID)
