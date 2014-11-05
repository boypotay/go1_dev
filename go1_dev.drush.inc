<?php
/**
 * @file ./go1_dev.drush.inc
 * 
 * @author Nguyen Tran <nguyen.tran@go1.com.au>
 */


/**
 * Implementation of hook_drush_command().
 */
function go1_dev_drush_command() {
  $items = array();
  
  $items['en-dl-modules'] = array(
    'description' => 'Enable list of modules, download them if not available.',
    'arguments' => array(
      'list' => 'List of module',
      ),
    'aliases' => array('edm'),
    'examples' => array(
      'drush edm views ctools' => 'Enable views and ctools module.',
      
      ),
  );
  return $items;
}

/**
 * Drush en-dl-modules command callback
 */
function drush_go1_dev_en_dl_modules($list) {
  $extensions = func_get_args();
  if(empty($extensions)) {
    drush_log(dt("They are not any extensions."), 'ok');
  } else {
    drush_print(dt('The following extensions will be enabled: !extensions', array('!extensions' => implode(', ', $extensions))));
  }
}

