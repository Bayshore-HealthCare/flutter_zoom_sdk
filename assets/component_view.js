
function dynamicallyLoadScript(url) {
    var script = document.createElement("script");  // create a script DOM node
    script.src = url;  // set its src to the provided URL
    document.head.appendChild(script);  // add it to the end of the head section of the page (could change 'head' to 'body' to add it to the end of the body section instead)
}

function startMeeting(
signature,
sdkKey,
meetingNumber,
userName,
passWord,
meetingLink
) {
 let browser= browserDetect()
 if(browser.includes("Firefox") || browser.includes("Safari")){
    window.open(meetingLink,'_blank');
    }
 else {

dynamicallyLoadScript("https://source.zoom.us/2.8.0/zoom-meeting-embedded-2.8.0.min.js")
const client = ZoomMtgEmbedded.createClient()
var meetingSDKElement = document.getElementById('meetingSDKElement')

client.init({
  zoomAppRoot: meetingSDKElement,
  language: 'en-US',
  customize: {
      video: {
        isResizable: true,
        viewSizes: {
          ribbon: {
            width:  350,
            height: innerHeight/2
          }
        }
      }
      }
}).then(()=>{
  client.join({
    sdkKey: sdkKey,
    signature: signature,
    meetingNumber: meetingNumber,
    password: passWord,
    userName: userName
  })
})

}
}


function browserDetect(){
navigator.saysWho = (() => {
  const { userAgent } = navigator
  let match = userAgent.match(/(opera|chrome|safari|firefox|msie|trident(?=\/))\/?\s*(\d+)/i) || []
  let temp

  if (/trident/i.test(match[1])) {
    temp = /\brv[ :]+(\d+)/g.exec(userAgent) || []

    return `IE ${temp[1] || ''}`
  }

  if (match[1] === 'Chrome') {
    temp = userAgent.match(/\b(OPR|Edge)\/(\d+)/)

    if (temp !== null) {
      return temp.slice(1).join(' ').replace('OPR', 'Opera')
    }

    temp = userAgent.match(/\b(Edg)\/(\d+)/)

    if (temp !== null) {
      return temp.slice(1).join(' ').replace('Edg', 'Edge (Chromium)')
    }
  }

  match = match[2] ? [ match[1], match[2] ] : [ navigator.appName, navigator.appVersion, '-?' ]
  temp = userAgent.match(/version\/(\d+)/i)

  if (temp !== null) {
    match.splice(1, 1, temp[1])
  }

  return match.join(' ')
})()
return navigator.saysWho
}
