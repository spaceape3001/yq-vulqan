////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/GraphicsCard.hpp>
#include <tachyon/os/GraphicsCardData.hpp>
#include <tachyon/os/GraphicsCardInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct GraphicsCardInfo::Repo {
        std::vector<const GraphicsCardInfo*> all;
    };
    
    GraphicsCardInfo::Repo& GraphicsCardInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const GraphicsCardInfo*>&    GraphicsCardInfo::all()
    {
        return repo().all;
    }

    GraphicsCardInfo::GraphicsCardInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::GraphicsCard);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    GraphicsCard::GraphicsCard(const Param& p) : Tachyon(p)
    {
    }

    GraphicsCard::~GraphicsCard()
    {
    }
    
    void GraphicsCard::snap(GraphicsCardSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void GraphicsCard::init_info()
    {
        auto w   = writer<GraphicsCard>();
        w.abstract();

        auto wt = writer<GraphicsCardID>();
        wt.description("Graphics Card Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<GraphicsCard>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GraphicsCard)
YQ_TYPE_IMPLEMENT(yq::tachyon::GraphicsCardID)
