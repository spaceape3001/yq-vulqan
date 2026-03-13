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
    class SetCount²Command : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount²Command, CountCommand)
    public:
        SetCount²Command(const Header&, const Vector2U&);
    
        const Vector2U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount²Command(const Header&);
        SetCount²Command(const SetCount²Command&, const Header&);
        ~SetCount²Command();

    private:
        Vector2U   m_count = ZERO;
        
        SetCount²Command(const SetCount²Command&) = delete;
        SetCount²Command(SetCount²Command&&) = delete;
        SetCount²Command& operator=(const SetCount²Command&) = delete;
        SetCount²Command& operator=(SetCount²Command&&) = delete;
    };
}
