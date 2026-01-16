////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "uicon.hpp"

#include <yq/core/ThreadId.hpp>
#include <yq/gluon/core/ustring.hpp>
#include <yq/gluon/core/Logging.hpp>
#include <yq/net/Url.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/text/match.hpp>

#include <QIcon>

namespace yq::tachyon {
    QIcon       qIcon(std::string_view sv)
    {
        if(!is_main_thread()){
            tachyonOnceWarning << "qIcon(" << sv << "): not the main thread";
            return QIcon();
        }
            
        Url u2  = Resource::resolve(sv);
        if(!is_similar(u2.scheme, "file")){
            tachyonFirstWarning(u2) << "qIcon(" << sv << "): not a local file";
            return QIcon();
        }
        if(!u2.fragment.empty()){
            tachyonFirstWarning(u2) << "qIcon(" << sv << "): has a fragment";
            return QIcon();
        }
        if(!u2.query.empty()){
            tachyonFirstWarning(u2) << "qIcon(" << sv << "): has a query";
            return QIcon();
        }
        if(!u2.host.empty()){
            tachyonFirstWarning(u2) << "qIcon(" << sv << "): has a host";
            return QIcon();
        }
        
        return QIcon(qString(u2.path));
    }
}
