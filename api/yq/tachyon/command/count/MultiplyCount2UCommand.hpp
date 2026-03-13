////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount²UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount²UCommand, CountCommand)
    public:
        MultiplyCount²UCommand(const Header&, const Vector2U&);
    
        const Vector2U&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyCount²UCommand(const MultiplyCount²UCommand&, const Header&);
        MultiplyCount²UCommand(const Header&);
        ~MultiplyCount²UCommand();

    private:
        Vector2U  m_δ;
        
        MultiplyCount²UCommand(const MultiplyCount²UCommand&) = delete;
        MultiplyCount²UCommand(MultiplyCount²UCommand&&) = delete;
        MultiplyCount²UCommand& operator=(const MultiplyCount²UCommand&) = delete;
        MultiplyCount²UCommand& operator=(MultiplyCount²UCommand&&) = delete;
    };
}
