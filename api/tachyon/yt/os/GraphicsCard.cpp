////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/os/GraphicsCard.hpp>
#include <yt/os/GraphicsCardData.hpp>
#include <yt/os/GraphicsCardInfoWriter.hpp>
#include <yt/msg/Post.hpp>

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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GraphicsCard)
