////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount¹UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount¹UCommand, CountCommand)
    public:
        SetCount¹UCommand(const Header&, const Vector1U&);
    
        const Vector1U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount¹UCommand(const Header&);
        SetCount¹UCommand(const SetCount¹UCommand&, const Header&);
        ~SetCount¹UCommand();

    private:
        Vector1U   m_count = ZERO;
        
        SetCount¹UCommand(const SetCount¹UCommand&) = delete;
        SetCount¹UCommand(SetCount¹UCommand&&) = delete;
        SetCount¹UCommand& operator=(const SetCount¹UCommand&) = delete;
        SetCount¹UCommand& operator=(SetCount¹UCommand&&) = delete;
    };
}
