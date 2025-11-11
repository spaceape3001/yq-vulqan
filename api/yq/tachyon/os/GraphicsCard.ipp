////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/GraphicsCardData.hpp>
#include <yq/tachyon/os/GraphicsCardMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct GraphicsCardMeta::Repo {
        std::vector<const GraphicsCardMeta*> all;
    };
    
    GraphicsCardMeta::Repo& GraphicsCardMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const GraphicsCardMeta*>&    GraphicsCardMeta::all()
    {
        return repo().all;
    }

    GraphicsCardMeta::GraphicsCardMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
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
    
    void GraphicsCard::init_meta()
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
