////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleScene.hpp"
#include <yq/tachyon/api/Domain.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/SceneMetaWriter.hpp>
#include <yq/tachyon/event/domain/DomainChangeEvent.hpp>
#include <yq/tachyon/command/domain/SetDomainCommand.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleScene)

namespace yq::tachyon {
    SimpleScene::SimpleScene() : SimpleScene(Param())
    {
    }
    
    SimpleScene::SimpleScene(const Param&p) : Scene(p)
    {
    }
    
    
    SimpleScene::~SimpleScene()
    {
    }

    void SimpleScene::on_set_domain_command(const SetDomainCommand& cmd)
    {
        if(cmd.target() != TypedID(*this))
            return;

        const Frame* current = Frame::current();
        if(!current)
            return;
            
        DomainID  old = m_domain;

        m_domain      = cmd.domain();
        send(new DomainChangeEvent({.source=*this}, current->typed(old), current->typed(m_domain)));
    }

    void    SimpleScene::snap(SceneSnap& sn) const
    {
        Scene::snap(sn);
        sn.domain   = m_domain;
        for(const TypedID& t : sn.children){
            if(t(Type::Camera))
                sn.cameras.push_back(t);
            if(t(Type::Light))
                sn.lights.push_back(t);
            if(t(Type::Rendered))
                sn.rendereds.push_back(t);
        }
    }
    
    void SimpleScene::init_meta()
    {   
        auto w = writer<SimpleScene>();
        w.description("Simple Scene, using child/parenting");
        w.slot(&SimpleScene::on_set_domain_command);
    }
}
