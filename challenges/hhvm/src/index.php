<?php

if (isset($_POST['username']) && isset($_POST['password'])){
    $valid_username = "admin";
    $valid_hash = "2f653afb9363fab7d7123658bdcf1c0a";
    $flag = "HXN{r4nd0m_f14g_f4r_d3m0}";

    
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';
    if (empty($username) || empty($password)){
        echo "Please provide credentials.\n";
        exit;
    }

    if (strlen($password) < 6){
        echo "Password does not match size criteria.\n";
        exit;
    }

    $hash = md5($password);
    
    if($hash == 0){
        highlight_file(__FILE__);
        exit;
    }
    
    if ($username === $valid_username && $hash === $valid_hash) {
        echo "Bienvenue, $username! \n";
    } else {
        echo "Nom d'utilisateur ou mot de passe incorrect.\n";
    }
}else{
    echo "Please log in";
}



?>
