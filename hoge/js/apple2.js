(function() {
  // PHPのURL
  var PHP_URL = "appleSet.php";
  // ボタン
  var btn_a;
  var btn_b;
  var btn_m;

  $(function() {
    btn_a = $("#btn1");
    btn_a.on("click", clickHandler_A);

    // LED_RをOFFにする
    appleSet("a_OFF");

    btn_b = $("#btn2");
    btn_b.on("click", clickHandler_B);

    // LED_BをOFFにする
    appleSet("b_OFF");

    btn_m = $("#btn3");
    btn_m.on("click", clickHandler_M);

    // LED_MをOFFにする
    appleSet("m_OFF");
  });

  /**
   * Click Handler
   */
  function clickHandler_A() {
    // ON -> OFF
    if(btn_a.attr("class") == "on") {
      btn_a.attr("class", "off");
      appleSet("a_OFF");
    }
    // OFF -> ON
    else {
      btn_a.attr("class", "on");
      appleSet("a_ON");
    }
  }

  function clickHandler_B() {
    // ON -> OFF
    if(btn_b.attr("class") == "on") {
      btn_b.attr("class", "off");
      appleSet("b_OFF");
    }
    // OFF -> ON
    else {
      btn_b.attr("class", "on");
      appleSet("b_ON");
    }
  }

  function clickHandler_M() {
    // ON -> OFF
    if(btn_m.attr("class") == "on") {
      btn_m.attr("class", "off");
      appleSet("m_OFF");
    }
    // OFF -> ON
    else {
      btn_m.attr("class", "on");
      appleSet("m_ON");
    }
  }

  /**
   * PHPにLEDの状態を送信します
   * @param	state	0:OFF, 1:ON
   */
  function appleSet(state) {
    $.ajax({
      url: PHP_URL,
      type: 'POST',
      dataType: 'json',
      data: {
        state: state
      }
    })
  }
})();



// $("#show").click(function() {
//   $("#show2").show('slow');
// }); 

$("#show").on("click", meme);

function meme() {
  $("#show2").show('slow');
}