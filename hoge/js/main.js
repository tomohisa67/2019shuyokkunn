'use strict';

{
  const Images = [
    'img/apple2.jpg',
    'img/banana2.jpg',
    'img/meron2.jpg',
  ];

  const btn1 = document.getElementById('btn1');
  const btn2 = document.getElementById('btn2');
  const btn3 = document.getElementById('btn3');

  const img = document.createElement('img');
  const main = document.querySelector('main');
  
  let current = 0;

  function setImage(image) {
    img.src = Images[image];
    img.classList.add('feed');
    main.appendChild(img);
  }
 
 btn1.addEventListener('click',() => {

    if(current === 0) {
      setImage(0);
 
      current++;
      return current;
    }else {
       main.removeChild(img);
       setImage(0);
 
       current++;
     return current;
    }

  });  
  
  btn2.addEventListener('click',() => {
 
      if(current === 0){
        setImage(1);
  
        current++;
        return current;
       }else {
        main.removeChild(img);
  
        setImage(1);
       
        current++;
        return current;
       }    
   
  });  
  
  btn3.addEventListener('click',() => {

      if(current === 0){
        setImage(2);
  
        current++;
        return current;
      }else {
        main.removeChild(img);
        
        setImage(2);
   
        current++;
        return current;
       }    
    
  });

  $('#btn1').click(function() {
    $('#btn1').val('1');
  });

  $('#btn2').click(function() {
    $('#btn2').val('2');
  });

  $('#btn3').click(function() {
    $('#btn3').val('3');
  });
  
}