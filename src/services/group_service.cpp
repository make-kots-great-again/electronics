#include "group_service.h"

boolean getGroupJWT(String groupId)
{   
    String endPoint = "/group/token/" + groupId;
    httpResp res = apiGET(endPoint);
    if(res.status == 200){
        setJWT(getObject(res.body)["token"]);
        dispCon_OK();
        return true;
    }
    else{
        dispCon_NOK();
        return false;
    }
}