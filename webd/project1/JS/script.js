gsap.to("#nav",{
    y:30,
    // backgroundColor:"#000",
    delay:0.5,
    height:"110px",
    backgroundColor:"green",
    scrollTrigger:{
        trigger:"#nav",
        scroller:"body",
        markers:true,
        start:"top -10%",
        end:"top -11%",
        scrub:1,// do everythhing on the basis of scrolling, it could ne true or false or a number
    }
})