////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize¹CMCommand, SizeCommand)
    public:
        SetMaxSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize¹CMCommand(const Header&);
        SetMaxSize¹CMCommand(const SetMaxSize¹CMCommand&, const Header&);
        ~SetMaxSize¹CMCommand();

    private:
        Size1CM   m_size = ZERO;
        
        SetMaxSize¹CMCommand(const SetMaxSize¹CMCommand&) = delete;
        SetMaxSize¹CMCommand(SetMaxSize¹CMCommand&&) = delete;
        SetMaxSize¹CMCommand& operator=(const SetMaxSize¹CMCommand&) = delete;
        SetMaxSize¹CMCommand& operator=(SetMaxSize¹CMCommand&&) = delete;
    };
}
