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

    GraphicsCardData::GraphicsCardData() = default;
    GraphicsCardData::~GraphicsCardData() = default;

    void GraphicsCardData::init_meta()
    {
        auto w = writer<GraphicsCardData>();
        w.description("Graphics Card Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    GraphicsCardSnap::GraphicsCardSnap() = default;
    GraphicsCardSnap::~GraphicsCardSnap() = default;

    void GraphicsCardSnap::init_meta()
    {
        auto w = writer<GraphicsCardSnap>();
        w.description("Graphics Card Snapshot");
        w.property("heap", READ_ONLY, &GraphicsCardSnap::heap);
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
YQ_OBJECT_IMPLEMENT(yq::tachyon::GraphicsCardData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::GraphicsCardSnap)
