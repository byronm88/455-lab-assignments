
<!DOCTYPE html>
<html>
<head>
<meta charset=utf-8 />
<title>buttton app</title>
  <script>
  function setColor(btn,color){

    var property=document.getElementById(btn);
   if (window.getComputedStyle(property).backgroundColor == 'rgb(244, 113, 33)') {
      property.style.backgroundColor=color;
   }
    else {
      property.style.backgroundColor = "#f47121";
    }
  }
  </script>

</head>
<body>
  <input type="button" id="btnAwesomeness" value="Button of Awesomeness" onclick="setColor('btnAwesomeness','#fff200');" />
</body>
</html>