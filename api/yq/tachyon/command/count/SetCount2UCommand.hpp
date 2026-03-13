////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount²UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount²UCommand, CountCommand)
    public:
        SetCount²UCommand(const Header&, const Vector2U&);
    
        const Vector2U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount²UCommand(const Header&);
        SetCount²UCommand(const SetCount²UCommand&, const Header&);
        ~SetCount²UCommand();

    private:
        Vector2U   m_count = ZERO;
        
        SetCount²UCommand(const SetCount²UCommand&) = delete;
        SetCount²UCommand(SetCount²UCommand&&) = delete;
        SetCount²UCommand& operator=(const SetCount²UCommand&) = delete;
        SetCount²UCommand& operator=(SetCount²UCommand&&) = delete;
    };
}
